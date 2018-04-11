/*
 * learning from: https://javascript.info
 */

"use strict";

function firstLesson() {
    //["hello", "world"].forEach(alert) // will raise two seperate alerts

    let message = 'oy there'; // store the string
    //alert(message)


    let user = 'John';
    let age = 25;
    let mesg = 'yo';

    const myBirthday = '10.1.0001';
    const COLOR_ORANGE = "#FF7F00";

    // back ticks allow embedded vars
    let phrase = `embedded ${user}, ${age} says ${mesg}`;
    alert(phrase);

    let boolean = true;
    let falseVar = false;
    let isGreater = 4 > 1;

    let nil = null; // set later?
    let undef;      // will be 'undefined'

    // alert(typeof phrase)
    // seven basic types: number, string, boolean, null, undefined, object, symbol

    // alert(Number("  123 ") + 1)
    // alert(1 + '2')

    // ** - exponentiation
    // ++/-- valid
    // >>> zero-fill right shift
    // === equality without type conversion

    /* didn't work: forgot to let the vars?
    for (a = 1, b = 3, c = a * b; a < 10; a++) {
        alert(a + b + c);
    }
    */

    let result = prompt("Tell me about it", "some_val"); // always supply default for IE
    alert(`result was: ${result}`);
    let likesCheese = confirm("Do you like cheese?");
    if (likesCheese || result == "I like cheese")
    {
        alert("Glad we agree");
    } // else if
    else // if (!likesCheese)
    {
        result = prompt("try again: Do you like cheese?", "yes");
    }

    // whiles are normal, do-while ok, for(;;) infinite, break normal, continue

    for (let i = 0; i < 3; i++) {
        alert(i);
    }
    // ?: allowed
    // weird break outer thing:
    /*
    outer:
    for(;;) {
        break outer; // goes to quasi-label outer
    }
    switch normal, with default:
    */
}

function functionLesson() {
    function newLession(value1, value2 = "default") {
        // local vars are normal
        alert(`newLesson() ${value1}, ${value2}`);
    }

    // compatible with strict style
    function oldStyleFunction(value, value2) {
        value = value || "default_value"
        if (value2 === undefined) {
            value2 = "default";
        }
        
        alert(value + " " + value2);
        
        return "hi";
        /* Don't do:
         * return // javascript inserts ; here
         *  (1); 
         */
    }

    let copyFunction = oldStyleFunction; // copy ptr to obj

    let altFuncDeclaration = function() {
        alert("altFunc called!");
        
        // could declare a local function if I wanted (functions are classes?)
        
    }; // need ; here to end function block...

    newLession("hi", 3);
    newLession("hi"); // value2 is undefined, unless set to default
    oldStyleFunction();
    alert(copyFunction);

    let lambda = (true) ? 
        (input) => {
            alert("truey" + input) 
            return "yo";
        }: 
        (input) => alert("falsey" + input);
        
    let result = lambda();
    alert(result);

    // debugger; <- breakpt
    // one line scope without brackets
}

function objectLesson() {
    //let user = new Object();
    /* Object properties are sorted if ints
     * others appear in creation order
     */
    let user = {
        name: "John",
        age: 30
    };
    
    //alert(`name: ${user.name}, age: ${user.age}`);
    
    delete user.age;
    
    if (user.age === undefined) {
        alert("deletion of user.age successful");
    }
    
    user["extra prop"] = "property"
    //alert(user["extra prop"]);
    
    user.age = 2034
    
    let contact = {
        [user.name]: user.age,
    }
    
    //alert(contact[user.name]);
    alert(user.name in contact); // will fail if name were defined to be 
                                 // undefined, in which case === is better

    function enumObject(obj) {
        let output = '';
        for (let key in obj) {
            output += `${key}: ${user[key]}` + '\n';
        }
        alert(output);
    }
    
    let blank = {};
    Object.assign(blank, contact, user); // dest, src, src1, ..
    
    enumObject(blank);
    // const objects can be changed, as the properties are not ro
    
    // on garbage collection!
}

objectLesson();
