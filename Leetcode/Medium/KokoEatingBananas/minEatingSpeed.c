int minEatingSpeed(int* piles, int pilesSize, int h) {
    long long left = 1;
    long long right = 0;

    for( int i = 0; i < pilesSize; i++ ) {
        if( piles[i] > right ) {
            right = piles[i];
        }
    }

    long long ans = right;

    while( left <= right ) {
        long long mid = left + ( right - left ) / 2;

        long long hours = 0;
        for(int i = 0; i < pilesSize; i++) {
            hours += (piles[i] + mid - 1) / mid;
        }

        if( hours <= h ) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return (int)ans;
}