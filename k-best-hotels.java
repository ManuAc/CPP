import java.util.ArrayList;
import java.util.List;

import lombok.Getter;

public class Solution {

    public static void main(String[] args) {

        List<HotelScore> hotelScores = new ArrayList<>();

        /**
         * hotelIds: 1, 2, 3, 4, 5 </br>
         * scores: 6, 9, 1, -6, 6
         */
        hotelScores.add(new HotelScore().hotelId(1).score(6));
        hotelScores.add(new HotelScore().hotelId(5).score(6));
        hotelScores.add(new HotelScore().hotelId(3).score(1));
        hotelScores.add(new HotelScore().hotelId(2).score(9));
        hotelScores.add(new HotelScore().hotelId(4).score(-6));

        /**
         * Extracts K best hotels given the score. If multiple hotels have the
         * same score, sorts the O/P based on the hotelId
         */
        int k = 2;
        List<HotelScore> kBestHotels = heapSort(hotelScores, k);

        kBestHotels.forEach(hotel -> {
            System.out.println(hotel.getHotelId());
        });
    }

    private static List<HotelScore> heapSort(List<HotelScore> scores, int k) {

        List<HotelScore> result = new ArrayList<>();

        int size = scores.size();

        for (int i = (size / 2) - 1; i >= 0; i--) {
            heapify(scores, size, i);
        }

        for (int i = size - 1; i >= 0 && k > 0; i--, k--) {

            // This will be one of the result
            result.add(scores.get(0));

            swapNodes(scores, i, 0);
            heapify(scores, i, 0);
        }

        return result;
    }

    private static void swapNodes(List<HotelScore> scores, int i, int j) {
        HotelScore temp = scores.get(i);
        scores.set(i, scores.get(j));
        scores.set(j, temp);
    }

    private static void heapify(List<HotelScore> scores, int size, int i) {

        int left = (i * 2) + 1;
        int right = (i * 2) + 2;

        HotelScore root = scores.get(i);

        int largest = i;

        if (left < size) {

            HotelScore leftNode = scores.get(left);

            if (leftNode.getScore() > root.getScore()) {
                largest = left;
            }

            if (leftNode.getScore() == root.getScore()) {
                if (leftNode.getHotelId() < root.getHotelId()) {
                    largest = left;
                }
            }
        }

        if (right < size) {

            HotelScore rightNode = scores.get(right);
            HotelScore largestSoFar = scores.get(largest);

            if (rightNode.getScore() > largestSoFar.getScore()) {
                largest = right;
            }

            if (rightNode.getScore() == largestSoFar.getScore()) {
                if (rightNode.getHotelId() < largestSoFar.getHotelId()) {
                    largest = right;
                }
            }
        }

        if (largest != i) {
            swapNodes(scores, largest, i);
            heapify(scores, size, largest);
        }

    }

    @Getter
    static class HotelScore {

        private int hotelId;
        private int score;

        public HotelScore hotelId(int hotelId) {
            this.hotelId = hotelId;
            return this;
        }

        public HotelScore score(int score) {
            this.score = score;
            return this;
        }
    }

}
