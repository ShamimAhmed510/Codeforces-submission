#include <bits//stdc++.h>

using namespace std;

void process_case()
{
    int size;
    cin >> size;

    vector<int> arr(size);
    vector<int> non_zero_pos;
    vector<int> one_pos;

    for (int idx = 0; idx < size; ++idx)
    {
        cin >> arr[idx];
        if (arr[idx] != 0)
        {
            non_zero_pos.push_back(idx);
        }
        if (arr[idx] == 1)
        {
            one_pos.push_back(idx);
        }
    }

    if (non_zero_pos.empty())
    {
        for (int idx = 0; idx < size; ++idx)
        {
            cout << arr[idx] << (idx == size - 1 ? "" : " ");
        }
        cout << "\n";
        return;
    }

    int opt_left = -1, opt_right = -1;
    int longest_span = -1;

    if (one_pos.empty())
    {
        opt_left = non_zero_pos.front();
        opt_right = non_zero_pos.back();
        if (opt_left != opt_right)
        {
            longest_span = opt_right - opt_left + 1;
        }
    }
    else
    {
        int first_one = one_pos.front();
        int last_one = one_pos.back();

        int leftmost_cand = non_zero_pos.front();
        int rightmost_cand = non_zero_pos.back();

        int span1 = first_one - leftmost_cand + 1;
        int span2 = rightmost_cand - last_one + 1;

        if (span1 >= span2)
        {
            longest_span = span1;
            opt_left = leftmost_cand;
            opt_right = first_one;
        }
        else
        {
            longest_span = span2;
            opt_left = last_one;
            opt_right = rightmost_cand;
        }
    }

    if (longest_span > 1 && opt_left != opt_right)
    {
        arr[opt_left] = 1;
        arr[opt_right] = 1;
    }
    else
    {
        arr[non_zero_pos[0]] = 1;
    }

    for (auto &val : arr)
    {
        if (val == -1)
        {
            val = 0;
        }
    }

    for (int idx = 0; idx < size; ++idx)
    {
        cout << arr[idx] << (idx == size - 1 ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    if (cin >> test_cases)
    {
        while (test_cases--)
        {
            process_case();
        }
    }

    return 0;
}
