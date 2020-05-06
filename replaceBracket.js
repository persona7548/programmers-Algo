function solution(p) {
    var answer = '';
    if(checkCorrect(p))return p;
    answer = recursive(p);
    return answer;
}
function recursive(p) {
    if(p.length ==0)return p;
    var i= 2;
    var u=p.substr(0,i),v=p.substr(i,p.length-i);
    while(!checkBalanced(u)){
        i+=2;
        u=p.substr(0,i);
        v=p.substr(i,p.length-i);
    }
    if(checkCorrect(u)){return u+recursive(v);}
    else{
        var tmp="(";
        tmp += recursive(v);
        tmp += ")";
        u = u.substr(1,u.length-2);
        u = u.split("");
        for(var i=0;i<u.length;i++){
            if(u[i]=="("){u[i]=")";}
            else{u[i]="(";}
        }
        tmp += u.join("");      
        return tmp;
    } 
   
}

function checkBalanced(p) {
    var tmp=0;
    for(var i=0;i<p.length;i++){
        if(p[i]=='('){tmp+=1;}
        else{tmp-=1;}
    }
    if(tmp==0){return true;}
    return false;
}

function checkCorrect(p) {
    var tmp=[];
    for(var i=0;i<p.length;i++){
        if(tmp[tmp.length-1] == "("  && p[i]==")" ){tmp.pop();}
        else{tmp.push(p[i]);}
    }
    if(tmp.length==0){return true;}
    return false;
}
