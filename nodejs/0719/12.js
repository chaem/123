/**
 * Created by DEVICE-01 on 2016-07-19.
 */


////////////*** 중요 ***/////////////
//차례대로 뺄 경우 뒷 수가 앞으로 당겨저서 뒤부터 빼는 for문을 사용
let array_test = [52,101,32,45,73,270,129,63];

//for (let i=0; i<array_test.length; i++) {
for (let i=array_test.length; i>=0; i--) {
    if (array_test[i] > 100) {
        array_test.splice(i, 1);

    }
}

console.log(array_test);