/**
 * Created by DEVICE-01 on 2016-07-19.
 */
// 자바스크립트 오브젝트 - c 구조체 같은 개념

let array_test = [
    {
        name : 'peach',
        hp : 50
    },
    {
        name : 'mango',
        hp : 100
    },
    {
        name : 'blueberry',
        hp : 250
    },
    {
        name : 'watermelon',
        hp : 700
    },
    {
        name : 'dragonfruit',
        hp : 1200
    }

];

console.log(array_test);

array_test.sort( (left, right)=> {
    return right.hp - left.hp;  //오름차순 (높은 순)
    //return left.hp - right.hp;  //내림차순 (낮은 순)
});  //left - 처음 값(복숭아와 hp50), right - 그 다음 값(...)

console.log('=======================');
console.log(array_test);