const { WebSocket } = require("ws");

const server = new WebSocket.Server({ port: 7071 });

const clients = new Map();

server.on("connection", (ws) => {
    const id = new Date().getTime();
    const metadata = { id };
    clients.set(ws, metadata);

    ws.on('message', (messageAsString) => {
        const metadata = clients.get(ws);
        const outbound = JSON.stringify({
            message: messageAsString
        });

        [...clients.keys()].forEach((client) => {
            client.send(outbound);
        });

        ws.on("close", () => {
            clients.delete(ws);
        });
    });
});
