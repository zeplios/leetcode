/* 这个题提交代码的时候没有C的选项，做起来也不容易，用了Java里很多字符串的操作 */
public class Solution {
    public boolean wordBreak(String s, Set<String> wordDict) {

		List<String> wd = new ArrayList<String>(wordDict);
		List<String> remove = new ArrayList<String>();
		for (String wd1 : wd) {
			if (!s.contains(wd1)) {
				remove.add(wd1);
			}
			if (wd1.equals(s))
				return true;
		}
		wd.removeAll(remove);
		remove.clear();
		Collections.sort(wd, new Comp());
		for (String wd1 : wd) {
			for (String wd2 : wd) {
				if (wd.contains(wd1 + wd2)) {
					remove.add(wd1 + wd2);
				}
			}
		}
		wd.removeAll(remove);
		return wordBreakHelper(s, wd);
	}

	public boolean wordBreakHelper(String s, List<String> wd) {
		if (s.length() == 0)
			return true;
		for (String w : wd) {
			if (s.startsWith(w)) {
				if (wordBreakHelper(s.substring(w.length()), wd)) {
					return true;
				}
			}
		}
		return false;
	}

	class Comp implements Comparator<String> {

		@Override
		public int compare(String o1, String o2) {
			return o2.length() - o1.length();
		}

	}
}