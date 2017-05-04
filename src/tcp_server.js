// Source:
// https://gist.github.com/tedmiston/5935757

// Include the TCP library
var net = require('net');

var server = net.createServer(function(socket) {
      socket.write('Echo server\r\n');
      socket.pipe(socket);
});

server.listen(1337, '127.0.0.1');

/* Connects from the command line
*nix utility for reading/writing across the tcp/udp network (debugging)

$ netcat 127.0.0.1 1337
Expected:
> Echo server

*/

/* Or use this example tcp client written in node.js.  (Originated with 
example code from 
http://www.hacksparrow.com/tcp-socket-programming-in-node-js.html.) */

var net = requrie('net');

var client = new net.Socket();
client.connect(1337, '127.0.0.1', function() {
      console.log('Connect successful');
      client.write('The server has been reached.');
});

client.on('data', function(data) {
    console.log('Received: ' + data);
    client.destroy(); // ends client after server response
});

client.on('close', function() {
    console.log('Connection closed');
});

/* Stdout:
   Connected
Received: Echo server
Hello, server! Love, Client.
Connection closed
*/
