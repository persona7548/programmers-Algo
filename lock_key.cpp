function solution(key, lock) {

    for (var k = 0; k < 4; k++) {
        for (var i = -(key.length - 1); i < key.length; i++) {
            for (var j = -(key.length - 1); j < key.length; j++) {
                if (openCheck(key, lock, i, j)) return true;
            }
        }
        key = rotate(key);
    }
    return false;
}

function openCheck(key, lock, x, y) {
    for (var i = 0; i < lock.length; i++) {
        for (var j = 0; j < lock.length; j++) {
            if ((i - x) < 0 || (j - y) < 0 ||(i - x)>=key.length ||(j - y)>=key.length) var value = 0;
            else { var value = key[i-x][j - y];}
            if (lock[i][j] + value != 1) return false;
        }
    }
    return true;
}

function rotate(key) {
    for (var i = 0; i < key.length / 2; i++) {
        for (var j = i; j < key.length - 1 - i; j++) {
            var Top = key[i][j];
            key[i][j] = key[key.length - 1 - j][i];
            key[key.length - 1 - j][i] = key[key.length - 1 - i][key.length - 1 - j];
            key[key.length - 1 - i][key.length - 1 - j] = key[j][key.length - 1 - i];
            key[j][key.length - 1 - i] = Top;
        }
    }
    return key;
}
