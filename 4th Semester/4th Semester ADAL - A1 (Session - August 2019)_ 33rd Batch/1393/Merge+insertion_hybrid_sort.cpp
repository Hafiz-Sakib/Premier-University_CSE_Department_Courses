/**
 * mohsin riad [1393]
 * merge+insertion hybrid sort
**/

#include<bits/stdc++.h>
using namespace  std;
typedef long long ll;

ll n;
ll arr[10005];
ll temp[10000];

void merging(ll lo,ll mid,ll hi);
void ins_sort(ll n);
void merge_sort(ll lo,ll hi);

int main()
{
    cout<<"enter the num. of elements: "<<endl;
    cin>>n;
    cout<<"random elements: "<<endl;

    for(int i=0; i<n ;i++)
        cin>>arr[i];

    merge_sort(0,n-1);
    cout<<"sorted elements: "<<endl;

    for(int i=0; i<n ;i++)
        cout<<arr[i]<<" ";

    return (0);
}

void merging(ll lo,ll mid,ll hi)
{
    ///cout<<"test: merge!!"<<endl;
    ll i=lo;
    ll j=lo;
    ll k=mid+1;

    while((i <= mid) && (k <= hi))
    {
        if(arr[i] <= arr[k])
        {
            temp[j] = arr[i];
            i++;
        }
        else
        {
            temp[j] = arr[k];
            k++;
        }
        j++;
    }
    if(i > mid)
        for(int p=k; p<=hi ;p++)
        {
            temp[j] = arr[p];
            j++;
        }
    else
        for(int p=i; p<=mid ;p++)
        {
            temp[j] = arr[p];
            j++;
        }
    for(int p=lo; p<=hi ;p++)
        arr[p] = temp[p];
}

void ins_sort(ll n)
{
    ///cout<<"test: insertion!!"<<endl;
    for(int j=1; j<=n ;j++)
    {
        ll item = arr[j];
        ll i = j-1;
        while((i >= 0) && (item < arr[i]))
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = item;
    }
}

void merge_sort(ll lo,ll hi)
{
    if((hi-lo) < 15) ins_sort(hi);
    else
    {
        //if(lo >= hi) return;
        ll mid  = (lo+hi)/2;
        merge_sort(lo,mid);
        merge_sort(mid+1,hi);
        merging (lo,mid,hi);
    }
}


/**
std input:

800
4606 6367 5035 9350 7261 184 4063 1598 2480 5790 967 2848 9456 5449 336 5383 9644 1610 7508 7136 9451 1547 2533 5176 7338 6158 1512 8410 9185 1548 7925 8580 1179 8841 775 7522 955 9807 2338 7201 5369 4023 2925 9355 6894 3066 723 798 641 6077 8085 2972 8157 834 9274 7913 338 709 1947 9175 6946 7999 5753 3217 1726 14 2965 8710 3380 454 6003 8616 4504 3905 9932 3754 7882 8360 5358 8956 9364 6846 5139 1004 1585 6417 2663 4290 5647 9827 185 2947 3217 3509 9740 5842 4336 7894 9340 2432 9139 1157 1848 3499 1314 9733 8122 7276 5342 3035 9858 2999 9372 8516 4129 4492 1078 1208 8624 8827 1515 7361 1662 5016 2371 9785 2242 5589 1246 4141 7201 6508 8654 1478 3352 9460 8150 3187 9405 6329 9612 5841 9340 6576 2134 5952 2389 2638 2925 7274 6524 9902 4155 4476 3834 7632 8808 4119 964 757 8974 7719 6843 630 8474 7404 4718 1658 6947 3316 11 5821 2783 1495 3362 57 2146 8865 9925 4180 1862 246 5564 7356 1746 9958 4875 7832 7391 5608 2026 7410 4398 6049 5405 1259 2752 4918 3062 8604 5227 4690 1894 4743 99 8533 8549 5404 9757 3950 9839 1861 7606 906 3688 2026 591 728 3423 1579 7622 9764 4701 8502 4661 6304 7530 1102 881 8988 7998 936 4504 6507 8016 3374 3440 1337 5677 1958 9548 5463 8014 2272 2389 3021 1304 1151 3196 7865 3490 9765 9775 211 9464 1847 3937 317 6304 4511 3448 5356 3882 6119 5418 2117 3279 8067 1519 5642 1559 3804 8862 6905 815 7752 8034 9601 9354 9247 8612 4271 8483 7463 5002 6648 8714 995 3366 5685 1771 4421 8533 6470 1747 7799 9631 4289 6168 1994 7855 1230 1136 9840 5209 780 7570 9260 4371 6352 8767 9846 3773 2032 7557 544 8740 4409 9311 7493 7655 6739 8736 8390 2696 9836 4482 1714 3373 7574 6388 4933 2969 3186 5695 9496 8308 3705 3610 1026 8415 6410 8775 5187 4235 9626 1776 4351 7918 628 788 3468 7098 432 2026 8744 1299 4074 9080 9137 6810 7947 4948 9230 3030 5980 165 8915 1352 1671 4057 3112 9324 2598 1310 9675 2242 7140 9243 6623 7001 894 2108 6277 8072 5847 9453 6682 5288 301 2226 8534 6235 4727 5127 4338 4430 4627 2560 566 4880 885 6028 3184 477 306 4973 1997 9520 3943 8184 7440 6494 2336 7603 4804 7348 5807 7132 6487 1646 2089 9062 8163 3563 7010 4603 8816 1353 7048 502 499 8551 9820 568 9939 4720 3277 313 7965 2125 353 8964 1877 4476 2448 3226 6027 9649 6946 3756 8035 3213 1980 1842 9375 5387 3740 6887 2234 7318 8047 3003 5314 2407 8155 6608 4273 6484 9678 8337 9391 2541 6521 297 7435 9364 9412 3827 8815 4060 6004 2287 4654 9975 2765 2864 2807 126 5252 5522 3556 5387 9562 2938 3895 4015 3281 3929 6815 3215 4351 9842 9468 9781 1304 7453 9972 5565 6176 7240 5325 9107 5270 7101 1471 2263 3433 9138 1292 5400 5401 9874 6097 5930 340 5487 3417 8336 9988 2305 4875 2142 7143 553 9459 5841 38 5839 5861 8876 7427 2409 2843 6802 4450 8094 4826 6411 2590 2819 1355 5694 4816 8720 3408 7594 8122 1826 6792 8280 8779 707 9199 5176 2175 8253 3764 393 7296 7351 6299 3326 7545 7149 4722 3439 4524 5907 7546 4724 1979 9736 6108 2552 4979 8805 609 4137 5831 3601 809 3523 9780 3080 5777 6329 2326 6253 60 8694 5187 7928 6563 2759 3838 3792 4877 4691 7834 4540 8978 7675 9641 9352 4974 5440 8818 2184 1461 9294 1428 6039 9660 6705 3877 3588 1287 8635 7211 5244 6485 2612 8661 5442 1948 9227 2803 7304 3294 3404 5697 5044 7931 1711 9642 5459 5677 9674 4660 342 2163 8347 6661 6538 5442 3736 6239 2398 9801 8949 5494 1940 2263 8303 8181 983 753 9071 9113 6194 2472 8280 684 925 5183 9327 9866 7752 5995 6294 8762 8716 9561 9217 592 5666 7972 6794 160 3409 8023 1941 662 9854 1473 5484 2585 6023 7257 3312 8678 7818 5660 8388 8059 8514 6001 7475 9361 1645 3164 6112 7572 8487 9263 8980 764 3896 769 4291 3856 8093 4453 1629 6897 7080 4178 6170 1592 3134 1481 3724 2946 7582 6006 9366 3827 9967 8283 7516 9043 2056 5832 1402 7959 3482 2988 5205 143 1539 6863 8976 9372 8043 1941 4965 185 6382 4419 6006 2317 7140 7928 5327 6421 2752 5072 6274 5169 4988 3595 3786 744 5798 827 4271 7121 8307 8721 8462 7466 1346 708 7865 5873 8887 9258 9120 7585 1743 6757 3659 607 21 6777 682 1355 7197 1727

**/