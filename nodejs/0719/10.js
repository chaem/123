/**
 * Created by DEVICE-01 on 2016-07-19.
 */

let array_test = ['banana', 'orange', 'apple', 'mango','strawberry'];

array_test.splice(2, 2, "grape","peanut");  //원하는 위치에 삽입 (위치, 삭제 개수) , 여러개 삽입 가능
console.log(array_test);

array_test.splice(2,1);  //삭제만 함
console.log(array_test);


// 추가하거나 삭제할때