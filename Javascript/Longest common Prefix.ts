const strs: string[] = ["flower","flow","flight"];

function longestCommonPrefix(strs: string[]){
    let n = strs.length;
    if(n == 0) return "";
    let common = "";
    let index = 0;

    while(true){
        for(let i=0; i<n; i++){
            if(i >= strs[0].length){
                return common;
            }
            let currentChar = strs[0][index];
            if(index > strs[i].length || strs[i][index] != currentChar){
                return common;
            }
            common += currentChar;
            index++
        }
    }
}

console.log(longestCommonPrefix(strs));
