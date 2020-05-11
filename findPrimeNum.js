function solution(n) {
    var field =[];
    var answer = 0;
    for(var i=2;i<=n;i++)field[i]=i;

    for(var i=2;i<=n;i++){
        if(!field[i])continue;
         for(var j=2*i;j<=n;j+=i){ 
             field[j]=0;
         }
    }
    for(var i=0;i<field.length;i++)if(field[i])answer++;
    return answer;
}
