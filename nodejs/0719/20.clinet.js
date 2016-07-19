/**
 * Created by DEVICE-01 on 2016-07-19.
 */
const net = require('net');

const ip = 'localhost';
const PORT = 192.168.0.21;

// 클라이언트도 마찬가지로 소켓이 필요 - 소켓을 자체적으로 생성
let socket = new net.Socket();

socket.connect(PORT, ip,()=> {  // 소켓으로 서버와 연결해서 연결되면 실행
    console.log("connect to : " + ip + PORT);
    let req = {
        name : 'chaem',
        value : 45
    }
    socket.write(JSON.stringify(req));

});

socket.on('data',(evt)=> {  // 데이터를 클라이언트가 받을 때
    console.log(String(evt));  // = evt.toString
    //socket.end("bye bye");  // 데이터를 보내고 나서 종료
    socket.destroy();
});

socket.on('error',(evt)=> {  // 에러가 발생할 때

});

socket.on('close',()=> {  // 접속을 종료할 때

});