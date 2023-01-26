class MedianFinder {
    std::list<int> list;
    std::list<int>::iterator med;
    int size = 0;
public:
    MedianFinder() {
                
    }
    
    void addNum(int num) {
        if (size == 0) {
            list.insert(list.begin(), num);
            ++size;
            med = list.begin();
        }
        else {
            auto it = list.begin();
            while (it != list.end() && *it < num)
                ++it;
            
            list.insert(it, num);        
            bool before = num <= *med;
            if (size % 2 == 1) {
                if (before)
                    --med;
            } else {
                if (!before)
                    ++med;
            }
            ++size;
        }
    }
    
    double findMedian() {
        double m;
        if (size % 2 == 1)
            m = *med;
        else {
            auto med2 = med;
            ++med2;
            m = (static_cast<double>(*med) + static_cast<double>(*med2)) / 2;
        }
        return m;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
