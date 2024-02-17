class Twitter:

    def __init__(self):
        self.counter = 0
        self.followed = {}
        self.tweets = {}


    def postTweet(self, userId: int, tweetId: int) -> None:
        c = self.counter
        self.counter += 1
        if userId in self.tweets.keys():
            self.tweets[userId].append((c, tweetId))
        else:
            self.tweets[userId] = [(c, tweetId)]        

    def getNewsFeed(self, userId: int) -> List[int]:
        list_followed = [userId] 
        if userId in self.followed.keys():
            list_followed += list(self.followed[userId])
    
        indices = []
        for f in list_followed:
            if f in self.tweets.keys():
                indices.append(len(self.tweets[f])-1)
            else:
                indices.append(-1)

        res = []
        while len(res) < 10:
            time = -1
            id = -1
            ind = -1
            for i, f in enumerate(list_followed):
                if indices[i] < 0:
                    continue
                a, b = self.tweets[f][indices[i]]
                if time == -1 or a > time:
                    time = a
                    id = b
                    ind = i
            if time != -1:
                res.append(id)
                indices[ind] -= 1
            else:
                break           
        return res

    
    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId in self.followed.keys():
            self.followed[followerId].add(followeeId)
        else:
            self.followed[followerId] = set([followeeId])

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followerId in self.followed.keys() and followeeId in self.followed[followerId]:
            self.followed[followerId].remove(followeeId)

        


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
