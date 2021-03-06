class Animal {
  abstract getAge(): number;

  greet(name: string): void {
    print('Hello, ' + name + '! My age is ' + getAge() + '.');
  }
}

class Dog extends Animal {
  var age: number;

  constructor(opts: {age: number}?) {
    this.age = opts?.age ?? 10;
  }

  getAge(): number {
    return this.age;
  }
}

function main(): void {
 var dog = new Dog({age: 35});
 dog.greet('Bob'); 
}
