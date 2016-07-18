/**
 * Created by DEVICE-01 on 2016-07-18.
 */

function foo() {
    console.log("it is foo");

}

var bar = foo;  //함수 자체를 변수화해서 넘겨줄 수 있다.
bar();