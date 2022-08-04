         //Reverse Linked List

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* currNext = curr->next;
            curr->next = prev;
            prev=curr;
            curr = currNext;
        }
        return prev;
    }
      
       // Middle of the Linked List

 Input: head = [1,2,3,4,5]
Output: [3,4,5]

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]

 ListNode* middleNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

                      // Merge Two Sorted Lists

 Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

    //MergeSort

    //recursion

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        if(l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next , l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1 , l2->next);
            return l2;
        }
    }
    T - n+m
    S-  n+m

    //iteration

     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* temp = new ListNode();
        ListNode* l3 = temp;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        temp->next = (l1) ? l1 : l2 ;
        
        return l3->next;
    }

    T - n+m
    S -  1

               //Remove Nth Node From End of List

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Input: head = [1], n = 1
Output: []

 //Two Pointer

 ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* slow=head;
        ListNode* fast = head;
        while(n)
        {
            fast=fast->next;
            n--;
        }
        if(fast == NULL) return head->next; // imp

        while(fast->next != NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next = slow->next->next;
        
        return head;
    }

               //Add two numbers as LinkedList

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0 , sum = 0;
        ListNode* temp = new ListNode();
        ListNode* l3 = temp;
        while(l1 || l2 || carry)
        {
            int x = (l1) ? l1->val : 0;
            int y = (l2) ? l2->val : 0;
            sum = x + y + carry;
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return l3->next;
    }
    T - max(n,m)
    S - max(n,m)
         
            //  Delete Node in a Linked List

//pointer dereferencing

Input: head = [4, 5, 1, 9], node = 5
Output : [4, 1, 9]

void deleteNode(ListNode* node)
    {
        ListNode* nextNode = node->next;
        *node = *nextNode;
        delete nextNode;
    }


            //Intersection of Two Linked Lists

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3

//Set
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        unordered_set<ListNode*> s1;

        while (headB)
        {
            s1.insert(headB);
            headB = headB->next;
        }

        while (headA)
        {
            if (s1.count(headA)) return headA;
            headA = headA->next;
        }
        return NULL;
    }


//Two pointer

    int getDiff(ListNode* headA, ListNode* headB)
    {
        int l1 = 0, l2 = 0;
        while (headA != NULL)
        {
            l1++;
            headA = headA->next;
        }
        while (headB != NULL)
        {
            l2++;
            headB = headB->next;
        }
        return l1 - l2;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        int diff = getDiff(headA, headB);

        if (diff < 0)
            while (diff++ != 0) headB = headB->next;
        else
            while (diff-- != 0) headA = headA->next;

        while (headA != NULL)
        {
            if (headA == headB) return headA;
            else
            {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }

    //Two pointer optimized

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA != pB)
        {
            pA = (pA != NULL) ? pA->next : headA;
            pB = (pB != NULL) ? pB->next : headB;
        }
        return pA;
    }

          //Detect a cycle in Linked List

//set

    bool hasCycle(ListNode* head)
    {
        unordered_set<ListNode*> st;
        while (head != NULL)
        {
            if (st.count(head)) return true;

            st.insert(head);
            head = head->next;
        }
        return false;
    }

    //Two pointer

    bool hasCycle(ListNode* head)
    {
        ListNode* slow = head, * fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        }
        return false;
    }


                                 //Reverse a LinkedList in groups of size k.
Input: head = [1, 2, 3, 4, 5], k = 2
Output : [2, 1, 4, 3, 5]

ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode* dummyhead = new ListNode();
    dummyhead->next = head;
    ListNode* pre = dummyhead;
    ListNode* cur = dummyhead, * nex = dummyhead;

    int len = 0;
    while (cur->next != NULL)
    {
        len++;
        cur = cur->next;
    }

    if (len == 0 || len == 1 || k == 0) return head;

    while (len >= k)
    {
        cur = pre->next;
        nex = cur->next;
        for (int i = 1; i < k; i++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        len = len - k;
        pre = cur;
    }
    return dummyhead->next;
}
t - n/k *k = (n)
s - 1  

           //Check if a LinkedList is palindrome or not.

Input: head = [1,2,2,1]
Output: true

// naive
bool isPalindrome(ListNode* head)
    {
        vector<int> A , B;
        ListNode *head1 = head;
        while(head != NULL)
        {
            A.push_back(head->val);
            head=head->next;
        }
        while(head1 != NULL)
        {
            B.push_back(head1->val);
            head1=head1->next;
        }
        reverse(B.begin() , B.end());
        return A==B;
    }
//2n
//2n

//Two Pointer

 ListNode *middleOfLL(ListNode *head)
    {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow=slow->next;
            fast=fast->next->next; 
        }
        return slow;
    }
    
    ListNode *reverseLL(ListNode *head)
    {
        ListNode *prev=NULL;
        ListNode *curr=head;
        while(curr != NULL)
        {
            ListNode *currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head)
    {
        ListNode *midLL = middleOfLL(head);
        
        ListNode *start2ndhalf = reverseLL(midLL->next);
        
        ListNode *p1=head , *p2=start2ndhalf;
        bool ans = true;
        
        while(ans && p2 != NULL )
        {
            if(p1->val != p2->val) ans=false;
            p1=p1->next;
            p2=p2->next;
        }
        
        midLL->next = reverseLL(start2ndhalf);
        
        return ans;
    }

    // n
    // 1

           //Linked List Cycle II
           //Find the starting point of the Loop of LinkedList

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1

//slow fast pointer
// l1 = nc-l2

ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL || head->next == NULL) return NULL;
        
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *entry=head;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow == fast)
            {
                while(entry != slow)
                {
                    entry=entry->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }

                //Flattening a Linked List

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.

// recursion to find last 2 ll
//start merging

Node *Merge2LL(Node *A , Node *B)
{
    Node *temp = new Node(0);
    Node *res = temp;
    
    while(A != NULL && B != NULL)
    {
        if(A->data < B->data)
        {
            temp->bottom = A;
            A = A->bottom;
        }
        else
        {
            temp->bottom = B;
            B=B->bottom;
        }
        temp = temp->bottom;
    }
    
    temp->bottom = A ? A : B;
    
    return res->bottom;
} 
    
Node *flatten(Node *root)
{
   if(root == NULL || root->next == NULL)
    return root;
    
    root->next = flatten(root->next);
    
    root = Merge2LL(root , root->next);
    
    return root;
}


              //Rotate List to right

Input: head = [1, 2, 3, 4, 5], k = 2
Output : [4, 5, 1, 2, 3]

//convert to circular LL

ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == NULL || head->next==NULL || k==0) return head;
        ListNode *temp = head;
        int n = 1;
        
        while(temp->next != NULL)
        {
            ++n;
            temp=temp->next;
        }
        
        temp->next = head;
        
        if(k > n) k=k % n; 
        int end = n - k;
        
        while(end)
        {
            temp=temp->next;
            --end;
        }
        head = temp->next;
        temp->next = NULL;
        
        return head;
    }

             //Clone a Linked List with random and next pointer

//hashmap

Node* copyRandomList(Node* head)
{
    map<Node*, Node*> m;
    Node* temp = head;
    while (temp)
    {
        m[temp] = new Node(temp->val);
        temp = temp->next;
    }
    temp = head;
    while(temp)
    {
        m[temp]->next = m[temp->next];
        m[temp]->random = m[temp->random];
        temp = temp->next;
    }
    return m[head];
}



//O(n) o(1) sol.

Node* copyRandomList(Node* head)
{
    Node* temp = head;
    Node* front;

    while (temp)
    {
        front = temp->next;
        Node* copy = new Node(temp->val);
        temp->next = copy;
        copy->next = front;
        temp = front;
    }

    temp = head;
    while (temp)
    {
        if (temp->random != NULL) temp->next->random = temp->random->next;
        temp = temp->next->next;
    }

    temp = head;

    Node* copy = new Node(0);
    Node* head1 = copy;

    while (temp)
    {
        front = temp->next->next;
        copy->next = temp->next;
        temp->next = front;
        temp = front;
        copy = copy->next;
    }

    return head1->next;
}

            //3Sum

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> ans;
    int n = nums.size(), target = 0;
    if (n == 0) return ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        long long target_2 = target - nums[i];

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            long long twosum = nums[left] + nums[right];

            if (twosum < target_2) left++;
            else if (twosum > target_2) right--;
            else
            {
                vector<int> triplet(3, 0);
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];

                ans.push_back(triplet);

                while (left < right && nums[left] == triplet[1]) left++;
                while (left < right && nums[right] == triplet[2]) right--;
            }
        }
        while (i + 1 < n && nums[i + 1] == nums[i]) i++;
    }
    return ans;
}

0(N*N)
o(M)=0(1)

           //Trapping Rain Water

//2 pointer

int trap(vector<int>& height)
{
    int left = 0, right = height.size() - 1, leftmax = 0, rightmax = 0, ans = 0;
    while (left < right)
    {
        if (height[left] <= height[right])
        {
            leftmax = max(leftmax, height[left]);
            ans += leftmax - height[left];
            left++;
        }
        else
        {
            rightmax = max(rightmax, height[right]);
            ans += rightmax - height[right];
            right--;
        }
    }
    return ans;
}

//n
//1

              //Remove Duplicates from Sorted Array

Input: nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
Output : 5, nums = [0, 1, 2, 3, 4, _, _, _, _, _]

//set

//two pointer

int removeDuplicates(vector<int>& nums)
{
    int n = nums.size(), i = 0;

    for (int j = 1; j < n; j++)
    {
        if (nums[j] != nums[i])
        {
            nums[++i] = nums[j];
        }
    }
    return i + 1;
}
          
              //Max Consecutive Ones

Input: nums = [1, 0, 1, 1, 0, 1]
Output : 2

int findMaxConsecutiveOnes(vector<int>& nums)
{
    int count = 0, maxcount = 0;
    for (int i : nums)
    {
        if (i == 1)
        {
            count++;
            maxcount = max(maxcount, count);
        }
        else count = 0;
    }
    return maxcount;
}