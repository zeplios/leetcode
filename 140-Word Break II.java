public class Solution {
    public List<String> wordBreak(String s, Set<String> wordDict) {
        List<String> wd = new ArrayList<String>(wordDict);
		List<String> remove = new ArrayList<String>();
		for (String wd1 : wd) {
			if (!s.contains(wd1)) {
				remove.add(wd1);
			}
		}
		wd.removeAll(remove);
		remove.clear();
		
		List<String> result = new ArrayList<String>();
		wordBreakHelper(s, wd, result, new ArrayList<String>());
		return result;
    }
    // return false means needn't seek any more
	// return true means found or this key failed, try another 
	public boolean wordBreakHelper(String s, List<String> wd, List<String> result, List<String> cur) {
		if (s.length() == 0) {
			StringBuilder sb = new StringBuilder();
			for (String c : cur) {
				sb.append(c);
				sb.append(" ");
			}
			result.add(sb.substring(0, sb.length()-1));
			return true;
		}
		for (String w : wd) {
			if (s.startsWith(w)) {
				cur.add(w);
				if (!wordBreakHelper(s.substring(w.length()), wd, result, cur)) {
					return false;
				}
				cur.remove(cur.size()-1);
			}
		}
		if (result.size() > 0) return true;
		for (String w : wd) {
			while (true) {
				int i = w.indexOf(s.charAt(0));
				if (i < 0) break;
				w = w.substring(i);
				if (s.startsWith(w)) {
					return true;
				}
				w = w.substring(1);
			}
		}
		return false;
	}
}