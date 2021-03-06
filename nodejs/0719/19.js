/**
 * Created by DEVICE-01 on 2016-07-19.
 */
const net = require('net');
const PORT = 8080;

let solution;
let bSolved = false;
solution = Math.round(Math.random() * 100);

net.createServer((socket)=> {
    console.log('connect : ' + socket.remoteAddress + ':' + socket.remotePort);
    // 누군가 들어오면 호출되는 부분

    // 자동으로 아래처럼 처리된다
    socket.on ('error',(evt)=> {  // 에러가 발생하면
        console.log(evt);
    });
    socket.on ('close',(evt)=> {  // 닫힘이 발생하면
        console.log("connection close")
        console.log(evt);
    });
    socket.on ('data',(evt)=> {  // 서버가 데이터를 받을 때
       //console.log (evt.toString);  // toString 보낼 데이터를 문자열로 변환
        let data = JSON.parse(evt.toString());

        if (bSolved == false) {
            console.log (data.name + " try game...");
            let resultObj = {};
            if (data.value > solution) {
                resultObj.txt = "high";
            }
            else if (data.value < solution) {
                resultObj.txt = "low";
            }
            else {
                resultObj.txt = "bingo";
                bSolved = true;
            }
        }
        else {
            resultObj.txt = "game over";
        }
        socket.write(JSON.stringify(resultObj));

    });

}).listen(PORT);

console.log('server listen :' + PORT);