class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low=INT_MAX;
        double high=INT_MIN;

        for(int i=0; i<squares.size(); i++){
            double x = squares[i][0];
            double y = squares[i][1];
            double s = squares[i][2];
            low = min(low, y);
            high = max(high, y+s);
        }
        for (int i=0; i<=88; i++) {
            double mid = (low + high)/2.0;
            if(call(squares,mid)) {
                low = mid;
            }        
            else high = mid;
        }
        return low;
    }

    int call(vector<vector<int>>& squares, double mid) {
        double above_area = 0;
        double below_area = 0;
        for(int i=0; i<squares.size(); i++){
            double x = squares[i][0];
            double y = squares[i][1];
            double s = squares[i][2];
           // below
double h1 = max(0.0, min(mid, y+s) - y);
below_area += h1 * s;

// above
double h2 = max(0.0, y+s - max(mid, y));
above_area += h2 * s;
            
        }
       
            if (above_area > below_area) return 2;
            else return 0;
    }
};