class Solution {
public:
    int poorPigs(int buckets, int poisonTime, int totalTime) {
    return ceil(log10(buckets) / log10(totalTime / poisonTime + 1));
}
};