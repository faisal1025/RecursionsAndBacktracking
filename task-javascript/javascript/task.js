const fs = require("fs");

let usage = `Usage :-
$ ./task add 2 hello world    # Add a new item with priority 2 and text "hello world" to the list
$ ./task ls                   # Show incomplete priority list items sorted by priority in ascending order
$ ./task del INDEX            # Delete the incomplete item with the given index
$ ./task done INDEX           # Mark the incomplete item with the given index as complete
$ ./task help                 # Show usage
$ ./task report               # Statistics`;


const begin = ()=>{
    console.log(usage);
};

const incompleteTask = ()=>{
    var result = '';
    try{
        const allTasks = fs.readFileSync(`${__dirname}/task.txt`, "utf8");
        var tasks = allTasks.split('\n');
    }catch{
        var tasks = [];
    }
    tasks.pop();
    tasks.sort((a, b)=>{
        return (Number(a[0]) - Number(b[0]));
    })
    for(let i = 1; i <= tasks.length; i++){
        var priority = tasks[i-1].slice(0,1);
        var task = tasks[i-1].slice(1);
        if(i == tasks.length){
            result += `${i}`+'.'+`${task} [${priority}]`;
            continue;
        }
        result += `${i}`+'.'+`${task} [${priority}]`+'\n';
    }
    if(tasks.length == 0){
        result = 'There are no pending tasks!';
    }
    console.log(result);
};

const add = (p_no, text)=>{
    if(p_no == undefined || text == undefined){
        console.log('Error: Missing tasks string. Nothing added!');
        return;
    }
    try{
        const allTasks = fs.readFileSync(`${__dirname}/task.txt`, "utf8");
        var tasks = allTasks.split('\n');
    }catch{
        var tasks = [];
    }
    tasks.pop();
    tasks.sort((a, b)=>{
        return (Number(a[0]) - Number(b[0]));
    })
    var flag = true;
    for(let i = 1; i <= tasks.length; i++){
        var priority = tasks[i-1].slice(0,1);
        var task = tasks[i-1].slice(1);
        if(p_no == Number(priority)){
            flag = false;
            break;
        }
    }
    if(flag == true){
        const filename = "task.txt";
        fs.appendFileSync(`${process.cwd()}/${filename}`, `${p_no} ${text}`+'\n', { encoding: "utf8", flag: "a" });
        console.log(`Added task: "${text}" with priority ${p_no}`);
    }else{
        console.log(`Element with the #${p_no} already exist.`);
    }
};

const deleteTask = (index)=>{
    if(index == undefined){
        console.log("Error: Missing NUMBER for deleting tasks.");
        return;
    }
    index -= 1;
    const allTasks = fs.readFileSync(`${__dirname}/task.txt`, "utf8");
    var tasks = allTasks.split('\n');
    tasks.pop();
    tasks.sort((a, b)=>{
        return (Number(a[0]) - Number(b[0]));
    })
    
    if(index >= 0 && index < tasks.length){
        var result = '';
        for(let i = 1; i <= tasks.length; i++){
            if(index == i-1) continue;
            var task = tasks[i-1];
            result = result.concat(task,'\n');            
        }
        const filename = "task.txt";
        fs.appendFileSync(`${process.cwd()}/${filename}`, `${result}`, { encoding: "utf8", flag: "w" });
        console.log(`Deleted task #${index+1}`);
    }else{
        console.log(`Error: task with index #${index+1} does not exist. Nothing deleted.`);
    }
};

const doneTask = (index)=>{
    if(index ==undefined){
        console.log("Error: Missing NUMBER for marking tasks as done.");
        return;
    }
    index -= 1;
    const allTasks = fs.readFileSync(`${__dirname}/task.txt`, "utf8");
    var tasks = allTasks.split('\n');
    tasks.pop();
    tasks.sort((a, b)=>{
        return (Number(a[0]) - Number(b[0]));
    })
    
    if(index >= 0 && index < tasks.length){
        var work = tasks[index].slice(1);
        const filename = "completed.txt";
        fs.appendFileSync(`${process.cwd()}/${filename}`, `${work}`+'\n', { encoding: "utf8", flag: "a" });
        var result = '';
        for(let i = 1; i <= tasks.length; i++){
            if(index == i-1) continue;
            var task = tasks[i-1];
            result = result.concat(task,'\n');            
        }
        fs.appendFileSync(`${process.cwd()}/task.txt`, `${result}`, { encoding: "utf8", flag: "w" });
        console.log('Marked item as done.');
    }else{
        console.log(`Error: no incomplete item with index #${index+1} exists.`);
    }
};

const reportTask = ()=>{
    var result = '';
    try{
        const allTasks = fs.readFileSync(`${__dirname}/task.txt`, "utf8");
        var tasks = allTasks.split('\n');
    }catch{
        var tasks = [];
    }
    tasks.pop();
    tasks.sort((a, b)=>{
        return (Number(a[0]) - Number(b[0]));
    })

    result += `Pending : ${tasks.length}`+'\n';
    for(let i = 1; i <= tasks.length; i++){
        var priority = tasks[i-1].slice(0,1);
        var task = tasks[i-1].slice(1);
        result += `${i}`+'.'+`${task} [${priority}]`+'\n';
    }
    result += '\n';
    try{
        const allCompleted = fs.readFileSync(`${__dirname}/completed.txt`, "utf8");
        var completed = allCompleted.split('\n');

    }catch{
        var completed = []
    }
    completed.pop();
    result += `Completed : ${completed.length}`+'\n';
    for(let i = 1; i <= completed.length; i++){
        if(i == completed.length){
            result += `${i}`+'.'+`${completed[i-1]}`;
            continue;
        }
        result += `${i}`+'.'+`${completed[i-1]}`+'\n';
    }
    console.log(result);
};


let command = process.argv[2];

if(command == 'help' || command == undefined){
    begin();
}else if(command == 'ls'){
    incompleteTask();
}else if(command == 'del'){
    let index = process.argv[3];
    deleteTask(index);
}else if(command == 'done'){
    let index = process.argv[3];
    doneTask(index);
}else if(command == 'report'){
    reportTask();
}else if(command == 'add'){
    let p_no = process.argv[3];
    let text = process.argv[4];
    add(p_no, text);
}
