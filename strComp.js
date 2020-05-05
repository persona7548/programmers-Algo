function solution(s) {
    var answer = s.length;
    for(var i=1;i<=s.length/2;i++){
        
        var subAnswer = "";
        var count =1;
        var mainTemp = s.substr(0,i);
        for(var j=i;j<=s.length;j=j+i){
            var subTemp = s.substr(j,i);
            if(mainTemp == subTemp){
                count++;
            }
            else{
                if(count == 1){subAnswer+=mainTemp;}
                else{subAnswer+=count+mainTemp}
                mainTemp = subTemp;
                var count =1;
            }
        }
        subAnswer= subAnswer.length;
        if(s.length%i>0)(subAnswer+=s.length%i);
        answer = answer>subAnswer?subAnswer:answer;

    }
    return answer;
}
