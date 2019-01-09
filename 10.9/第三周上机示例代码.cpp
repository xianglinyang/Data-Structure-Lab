// Week 3_1

bool checkInclusion(string s1, string s2) {
	char characters1[256] = { 0 };
	for (char c : s1) {
		characters1[c - NULL] += 1;
	}

	char characters2[256] = { 0 };
	for (int i = 0, j = i + s1.size(); j <= s2.size(); i++, j++) {
		//Count characters in current window in s2.
		for (int k = i; k < j; k++) {
			if (characters1[s2[k] - NULL] == 0) break;
			else characters2[s2[k] - NULL] += 1;
		}
		// Judge. Clear the counter
		for (int k = 0; k < 256; k++) {
			if (characters1[k] == characters2[k]) {
				if (k == 255) return true;
				else characters2[k] = 0;  //Clear characters2
			}
			else if (k < 255) {
				for (int l = k; l < 256; l++)  // Continue clearing characters2.
					characters2[l] = 0;
				break;
			}
		}
	}

	return false;

// Week 3_2
/*
 * 在窗口移动过程中，每次只删除、插入一个节点即可获取有序的窗口
 * 无需每次都对窗口内的节点重新插入
 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> res;
    ListNode * head = NULL;

    for(int i = 0; i < k; i++)
        head = insertNode(head, nums[i]);
    res.push_back(getMedian(head, k));

    for(int i = k; i < nums.size(); i++){
        head = deleteNode(head, nums[i-k]);  // 每次只更新一个节点即可解决，因此复杂度为k
        head = insertNode(head, nums[i]);
        res.push_back(getMedian(head, k));  // 寻找中位数，复杂度为k/2
    }

    return res;
}

ListNode* insertNode(ListNode *head, int x){
        if(!head || x <= head->val){
        ListNode *node = new ListNode(x);
        node->next = head;
        return node;
    }

    ListNode* node = head;
    while(node->next && x > node->next->val) node = node->next;
    ListNode *temp = node->next;
    node->next = new ListNode(x);
    node->next->next = temp;
    return head;
}

ListNode* deleteNode(ListNode *head, int x){
    if(x == head->val)
        return head->next;

    ListNode* node = head;
    while(node->next && node->next->val != x) node = node->next;
    node->next = node->next->next;
    return head;
}

double getMedian(ListNode *head, int k){
    int step = (k-1) / 2;
    ListNode *node = head;
    while(step--)
        node = node->next;

    if(k % 2) return node->val;
    return node->val / 2.0 + node->next->val / 2.0; // In case of overflow
}