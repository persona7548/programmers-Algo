function solution(words, queries) {
    var answer = [];
    for(var i=0;i<queries.length;i++){
        var count =0;
        for(var j=0;j<words.length;j++){
            if(wordCheck(words[j], queries[i]))count++;
        }
        answer.push(count);

    }
    return answer;
}

function trie(words){
    for(var i=0;i<words.length;i++){
        for(var j=0;j<words[i].length;j++){
           
        }
    }

}
function wordCheck(words, queries){
    if(words.length!=queries.length)return false;
    if(queries[0]=='?'){
        for(var i=words.length-1;i>=0;i++){
            if(queries[i]=='?')break;
            if(words[i]!=queries[i])return false;
        }
        return true;

    }else{
    for(var i=0;i<words.length;i++){
        if(queries[i]=='?')break;
        if(words[i]!=queries[i])return false;
    }
    return true;}
}
