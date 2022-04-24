class Solution {
private:
    int gcd(int a,int b)
      {
          if(b == 0) {
             return a;
          }
         return gcd(b,a%b);
	 }
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(targetCapacity > jug1Capacity+jug2Capacity) return false;
        
        return targetCapacity%gcd(jug1Capacity,jug2Capacity) == 0;
    }
};