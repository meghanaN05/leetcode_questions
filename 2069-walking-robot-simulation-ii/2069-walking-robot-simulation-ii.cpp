class Robot {
public:
    int i = 0;
    vector<vector<int>> pos;
    bool moved = false;
    Robot(int width, int height) {
        for (int j = 0; j < width; j++) {
            pos.push_back({j, 0, 0});
        }
        for (int j = 1; j < height; j++) {
            pos.push_back({width - 1, j, 1});
        }
        for (int j = width - 2; j >= 0; j--) {
            pos.push_back({j, height - 1, 2});
        }
        for (int j = height - 2; j >= 1; j--) {
            pos.push_back({0, j, 3});
        }
        pos[0][2]=3;
    }

    void step(int num) {
        moved = true;
        i = (i + num) % pos.size();   
    }

    vector<int> getPos() {
        return {pos[i][0], pos[i][1]};
    }

    string getDir() {
        if (!moved) return "East";
        int x = pos[i][2];   
        if (x == 0) return "East";
        if (x == 1) return "North";
        if (x == 2) return "West";
        return "South";      
    }
};