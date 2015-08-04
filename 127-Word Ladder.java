public class Solution {
    public int ladderLength(String beginWord, String endWord, Set<String> wordDict) {
		List<String> wd = new ArrayList<String>(wordDict);
		Set<String> used = new HashSet<String>();
		used.add(endWord);
		int preSize = wd.size() + 1;
		int diff = 1;
		while (preSize != wd.size()) {
			preSize = wd.size();
			Set<String> newused = new HashSet<String>();
			for (String s : used) {
				if (canTrans(s, beginWord)) {
					return diff + 1;
				}
			}
			for (String s : used) {
				for (int i = 0 ; i < wd.size() ; i++) {
					String t = wd.get(i);
					if (canTrans(s, t)) {
						newused.add(t);
						wd.remove(i);
						i--;
					}
				}
			}
			used = newused;
			diff++;
		}
		return 0;
    }

	public boolean canTrans(String s1, String s2) {
		if (s1.length() != s2.length()) return false;
		int diff = 0;
		for (int i = 0 ; i < s1.length() ; i++) {
			if (s1.charAt(i) != s2.charAt(i)) diff++;
			if (diff > 1) return false;
		}
		return true;
	}
}