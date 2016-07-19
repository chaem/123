/**
 * Created by DEVICE-01 on 2016-07-19.
 */

let buf = new Buffer(8);  // 8byte(64bit) 메모리 할당

buf.writeInt32BE(0x01020304,0);  // 우리가 읽는 순서대로 값을 저장
buf.writeInt32LE(0x01020304,4);  // 거꾸로 저장

console.log(buf);

//////////////////

let buf2 = new Buffer(2);  // 2byte(16bit)

//우리가 보기에 편한
buf2.writeInt16BE(7);  // 높은 번지에 낮은 숫자
console.log(buf2);

//기계적인 표현법 - 읽기는 힘들지만 속도는 더 빠르다
buf2.writeInt16LE(7);  // 낮은 번지에 낮은 숫자
console.log(buf2);

//////////////////

let buf3 = new Buffer([0x00,0x07]);  //16비트 정수형 빅엔디언
let a = buf3.readInt16BE();  //버퍼3 읽음
console.log('a = ' + a);
let b = buf3.readInt16LE();  //빅엔디언 값을 리틀엔디언으로 부름
console.log('b = ' + b);  //바라는 값이 나오지 않는다