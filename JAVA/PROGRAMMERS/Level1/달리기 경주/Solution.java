import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = new String[players.length];

		HashMap<String, Integer> mp = new HashMap<>();
		HashMap<Integer, String> mr = new HashMap<>();

		for (int i = 0; i < players.length; i++) {
			mp.put(players[i], i);
			mr.put(i, players[i]);
		}

		for (int i = 0; i < callings.length; i++) {
			int currentRank = mp.get(callings[i]);
			String player = mr.get(currentRank);

			String frontPlayer = mr.get(currentRank - 1);

			mp.put(player, currentRank - 1);
			mp.put(frontPlayer, currentRank);

			mr.put(currentRank - 1, player);
			mr.put(currentRank, frontPlayer);
		}

		for (int i = 0; i < players.length; i++) {
			answer[i] = mr.get(i);
		}

		return answer;
    }
}
