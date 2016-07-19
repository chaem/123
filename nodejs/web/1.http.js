/**
 * Created by DEVICE-01 on 2016-07-19.
 */
////////////// 웹 게임 서버 /////////////////

const http = require('http');
const util = require('util');
const os = require('os');
const UrlParser = require('url');

let solution;
let bSolved = true;
let AdminPasswd = "이채민";

let http_server = http.createServer(
    (req, res)=> {  // req = 클라이언트에서 나에게 보낸 데이터, res = 내가 보낼 데이터
        console.log(req.url);

        var result = UrlParser.paser(req.url,true);  // Url을 파싱한다
        console.log(result);

        let header = {
            'Access-Control-Allow-Origin': '*',
            'Access-Control-Allow-Methods': 'GET',
            'Access-Control-Max-Age': '1000'
        };
        header['Content-Type'] = 'text/plain';
        res.writeHead(200,header);  //res 데이터를 헤더로 보낸다 (페이지를 찾을 수 없습니다가 아닌 200은 정상 - 적합한 요청이다)

        switch (url_obj.pathname) {
            case '/sum' :
                let c = parseInt(url_obj.query.a) + parseInt(url_obj.query.b);
                res.end("result : " + c);
                break;
            case '/game-try' :
                if (bSolved == false) {
                    if (url_obj.query.value == solution) {
                        winner_name = url_obj.query.name;
                        res.end("bingo");
                    }
                    else if (url_obj.query.value > solution) {
                        red.end("high");
                    }
                    else if (url_obj.query.value > solution) {
                        red.end("low");
                    }
                }
                else {
                    res.end(solution + "game over, winner is " + winner_name);
                }
                break;
            case '/start-game' :
                if (url_obj.query.passwd == AdminPasswd) {
                    solution = Math.round(Math.random() * 100);
                    bSolved = false;
                    winner_name = "";
                    res.end("start ok : " + solution);
                }
                else {
                    res.end("wrong passwd");
                }
                break;
            default :
                res.end("it is bingo api server");
                break;
        }
    }
);
http_server.listen(8080);