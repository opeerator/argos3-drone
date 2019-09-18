server = require("socket").bind("*", 8080)

if not server then
   print("could not start server")
else
   server:settimeout(0.1)
   print("server started on " .. server:getsockname())
   clients = {}

   while true do
      -- handle new connection
      local client, status = server:accept()
      if not status then
         client:settimeout(0.1)
         clients[#clients + 1] = client
         print(client:getsockname() .." connected at " .. os.date("%H:%M:%S"))
      end
      -- route data between connected clients
      for index, rx_client in ipairs(clients) do
         local data, rx_status = rx_client:receive() -- accept data from sender

         -- testing
         if rx_status and rx_status ~= "timeout" then
            print("rx_status" .. rx_status)
         end

         if data then
            print("data" .. data)
            for index, tx_client in ipairs(clients) do
               if tx_client ~= rx_client then
                  -- best effort: try to send data before timeout
                  tx_client:send(data)
               end
            end
         elseif rx_status == "closed" then
            -- remove disconnected client
            for index = index, #clients - 1 do
               clients[index] = clients[index + 1]
            end
            clients[#clients] = nil
            -- restart the inner loop
            break
         end
      end
   end
end

