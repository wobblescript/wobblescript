type FooBar = {foo: string};

function main(): void {
  // Arrays in WobbleScript are typed.
  //
  // This helps the compiler efficiently produce programs.
  var array = <FooBar>[{foo: "bar"}];

  // Providing items of a single type will create an
  // implicitly-typed array.
  var array2 = [{foo: "bar"}];

  // Use a for ... of loop to loop through each item.
  for (var item of array) {
    print('Foo: ' + item.foo);
  }
}
