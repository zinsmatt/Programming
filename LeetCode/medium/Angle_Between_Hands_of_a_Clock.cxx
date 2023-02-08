class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle_h = (hour % 12) * 360 / 12 + (static_cast<double>(minutes) / 60) * (360/12);
        double angle_m = (static_cast<double>(minutes) / 60) * 360;

        double diff = abs(angle_h - angle_m) ;
        if (diff > 180)
            diff = 360 - diff;
        return diff;
    }
};
