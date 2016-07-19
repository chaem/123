/**
 * Created by DEVICE-01 on 2016-07-19.
 */

let array_test = ['banana', 'orange', 'apple'];
console.log(array_test);

//////////////////////////
array_test.push('grape');  // 뒤에 추가하기
console.log(array_test);

console.log( '추출 : ' + array_test.shift());  // 앞부분 빼기
console.log(array_test);

array_test.unshift('raspberry');  //앞에 추가하기
console.log(array_test);

array_test.pop();  //뒷부분 빼기
console.log(array_test);