#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    int time = 0;

    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time, tweetId});
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;

        // max heap: (time, tweetId, userId, index)
        priority_queue<tuple<int,int,int,int>> pq;

        // include self
        following[userId].insert(userId);

        // 🔹 convert set to vector for index-based loop
        vector<int> users;
        for (auto it = following[userId].begin(); it != following[userId].end(); it++) {
            users.push_back(*it);
        }

        // 🔹 index-based loop
        for (int i = 0; i < users.size(); i++) {
            int user = users[i];

            if (tweets[user].size() > 0) {
                int idx = tweets[user].size() - 1;

                int t = tweets[user][idx].first;
                int tid = tweets[user][idx].second;

                pq.push({t, tid, user, idx});
            }
        }

        // 🔹 get top 10 tweets
        while (!pq.empty() && result.size() < 10) {

            auto top = pq.top();
            pq.pop();

            int t = get<0>(top);
            int tid = get<1>(top);
            int user = get<2>(top);
            int idx = get<3>(top);

            result.push_back(tid);

            // push next older tweet
            if (idx > 0) {
                int nt = tweets[user][idx - 1].first;
                int ntid = tweets[user][idx - 1].second;

                pq.push({nt, ntid, user, idx - 1});
            }
        }

        return result;
    }
};
