class MovieRentingSystem {
    unordered_map<int, set<pair<int,int>>> unrented;
    set<tuple<int,int,int>> rented;
    unordered_map<long long, int> priceMap;

    long long encode(int shop, int movie) {
        return ((long long)shop << 20) | movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[encode(shop, movie)] = price;
            unrented[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        if (!unrented.count(movie)) return res;
        int cnt = 0;
        for (auto &p : unrented[movie]) {
            res.push_back(p.second);
            if (++cnt == 5) break;
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = priceMap[encode(shop, movie)];
        unrented[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = priceMap[encode(shop, movie)];
        rented.erase({price, shop, movie});
        unrented[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto &t : rented) {
            auto [price, shop, movie] = t;
            res.push_back({shop, movie});
            if (++cnt == 5) break;
        }
        return res;
    }
};
