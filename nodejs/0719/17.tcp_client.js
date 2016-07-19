/**
 * Created by DEVICE-01 on 2016-07-19.
 */
////////// 서버와 연결할 클라이언트 생성 ////////
    //서버는 기다리기만 하고 클라이언트가 연결//

const net = require('net');

const ip = 'localhost';
const PORT = 8080;

// 클라이언트도 마찬가지로 소켓이 필요 - 소켓을 자체적으로 생성
let socket = new net.Socket();

socket.connect(PORT, ip,()=> {  // 소켓으로 서버와 연결해서 연결되면 실행
   console.log("connect to : " + ip + PORT);
    socket.write("여보세요");

});

socket.on('data',(evt)=> {  // 데이터를 클라이언트가 받을 때
    console.log(String(evt));  // = evt.toString
    socket.end("bye bye");  // 데이터를 보내고 나서 종료
});

socket.on('error',(evt)=> {  // 에러가 발생할 때

});

socket.on('close',()=> {  // 접속을 종료할 때

});