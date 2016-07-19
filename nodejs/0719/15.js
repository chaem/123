/**
 * Created by DEVICE-01 on 2016-07-19.
 */

let buff = new Buffer(4);

buff.writeFloatBE(3.14);
console.log(buff);

buff.writeFloatLE(3.14);
console.log(buff);

//우리는 3.14 라는 값을 보내지만 BE와 LE처럼 기계는 값을 다르게 받아들일 수 있다.