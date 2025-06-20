class Solution {
public:
    int maxDistance(string directions, int maxChanges) {
        int maxDist = 0, northMoves = 0, southMoves = 0, eastMoves = 0, westMoves = 0;
        
        for (int i = 0; i < directions.size(); i++) {
            if (directions[i] == 'N') northMoves++;
            if (directions[i] == 'S') southMoves++;
            if (directions[i] == 'E') eastMoves++;
            if (directions[i] == 'W') westMoves++;
            
            int verticalDist = abs(northMoves - southMoves);
            int horizontalDist = abs(eastMoves - westMoves);
            int initialDist = verticalDist + horizontalDist;
            int adjustedDist = initialDist + min(2 * maxChanges, i + 1 - initialDist);
            
            maxDist = max(maxDist, adjustedDist);
        }
        
        return maxDist;
    }
};
