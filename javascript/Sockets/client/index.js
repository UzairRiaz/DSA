const ws = new WebSocket(`ws://localhost:7071`);
var id;
// Log socket opening and closing
ws.addEventListener("open", event => {
    // generate random hex string of length 6
    id = Math.random().toString(16).substr(2, 6);
    console.log("Websocket connection opened");
});

ws.addEventListener("close", event => {
    console.log("Websocket connection closed");
});

ws.onmessage = function ({ data }) {
    const decodedData = JSON.parse(data);

    var enc = new TextDecoder("utf-8");
    var arr = new Uint8Array(decodedData.message.data);
    var msg = enc.decode(arr);
    msg = JSON.parse(msg);

    const msgDiv = document.createElement('div');
    if (msg.id == id) {
        msgDiv.classList.add('sent');
    } else {
        msgDiv.classList.add('received');
    }
    msgDiv.innerHTML = `${msg.id}: ${msg.message}`;
    msgDiv.style.backgroundColor = `#${msg.id}`;
    document.getElementById('messages').appendChild(msgDiv);

}
const form = document.getElementById('msgForm');
form.addEventListener('submit', (event) => {
    event.preventDefault();
    const message = document.getElementById('inputBox').value;
    const outboundMessage = {
        id: id,
        message: message
    }
    ws.send(JSON.stringify(outboundMessage));
    document.getElementById('inputBox').value = ''
})