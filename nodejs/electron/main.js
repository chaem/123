/**
 * Created by DEVICE-01 on 2016-07-19.
 */

const electon = require('electron');
const {app} = electron;  // electron 안에 app 이라는 개체가 있다
const {BrowserWindow} = electron;
let win;
function createWindow() {
    win = new BrowserWindow({width : 800, height : 600});  // 새로운 창 생성

    win.loadURL("file://${__dirname}/index.html");

    win.on('closed',()=> {  // 창을 닫을 경우
       win = null;
    });
}

app.on('ready',createWindow);  // app이 처음 실행될 때
app.on('activate',()=> {  // 창이 활성화될 때 (비활성화 상태에서)
   if (win == null) {
       createWindow();
   } 
});
app.on('window-all-closed',()=> {
   if (process.platform !== 'darwin') {
       app.quit();
   }
});