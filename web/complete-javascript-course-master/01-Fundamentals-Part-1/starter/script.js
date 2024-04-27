alert('YIPPIEEEEE');
console.log(5 + 8);

// Values and Variables
let vari = "honnas";

const names = [vari, 'huun', 'hann', 'hiin', 'heen'];

for (let i = 0; i < names.length; i++) {
    console.log('name: ' + names[i]);
}

let numberType = 23;
let boolType = true;
let undefinedType;

console.log(typeof(undefinedType));

// diferença entre LET e VAR
// var declara uma variavel de escopo GLOBAL
// let declara uma variavel de escopo limitado ao seu bloco.


// operators
let x = 10;
x += 2;
x++;
x--;
console.log(x); // 12
let y = 14
console.log(y >= x) // true