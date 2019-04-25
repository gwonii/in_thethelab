# Callback

# 1. Callback 함수란? 

* 다른 함수의 인자로써 이용되는 함수 
* 어떤 이벤트에 의해 호출되어지는 함수 

# 2. 예제 

```pseudocode
function greeting(name){
    alert("hi,hello. " + name);
}

function callbackTest(callback){
    var name = prompt("이름을 입력해주라.");
    callback(name);
}

callbackTest(greeting);
```



# 