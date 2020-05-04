function solution(heights) {
    var answer = [];
    answer.push(0);
    for(var i= 1;i<heights.length;i++){
        var findTower =0;
        for(var j=i-1;j>=0;j--){
            if(heights[j]>heights[i]){
                findTower++;
                answer.push(j+1);
                break;
            }
        }
        if(!findTower)answer.push(0);
    }

    return answer;
}
