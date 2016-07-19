/**
 * Created by DEVICE-01 on 2016-07-19.
 */

let test = new buffer([0x41, 0x42, 0x43]);
//server에서 값을 받을때 무조건 버퍼형식으로 받는다.

console.log(test);
console.log(test[1]);

// 버퍼를 문자열로 변환
console.log(String(test));
console.log(String.fromCharCode(test[1])); // 한가지만 문자열로 변환 (0x42)
