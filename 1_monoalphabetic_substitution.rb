orig_input = "JGRMQOYGHMVBJWRWQFPWHGFFDQGFPFZRKBEEBJIZQQOCIBZKLFAFGQVFZFWWEOGWOPFGFHWOLPHLRLOLFDMFGQWBLWBWQOLKFWBYLBLYLFSFLJGRMQBOLWJVFPFWQVHQWFFPQOQVFPQOCFPOGFWFJIGFQVHLHLROQVFGWJVFPFOLFHGQVQVFILEOGQILHQFQGIQVVOSFAFGBWQVHQWIJVWJVFPFWHGFIWIHZZRQGBABHZQOCGFHX"
input = orig_input.downcase().split('')
decoded = []
letter_map = {}
alphabet_letter_frequency = { :a => 8.2, :b => 1.5, :c => 2.8, :d => 4.3, :e => 12.7, :f => 2.2, :g => 2.0, :h => 6.1, :i => 7.0, :j => 0.2, :k => 0.8, :l => 4.0, :m => 2.4, :n => 6.7, :o => 7.5, :p => 1.9, :q => 0.1, :r => 6.0, :s => 6.3, :t => 9.1, :u => 2.8, :v => 1.0, :w => 2.4, :x => 0.2, :y => 2.0, :z => 0.1 }
margin_error = 0.6
done = []

input.each do |i|
  unless done.include?(i)
    n_occurance = 1.0

    input.each do |j|
      if i == j
        n_occurance = n_occurance + 1
      end
    end

    letter_map[i] = (n_occurance / input.length * 100).round(2)
  end

  done.push(i)
end

placement = {}
new_string = []

(0..input.length).each do |i|
  placement[input[i]] = []
  (0..input.length).each do |j|
    if input[j] == input[i]
      placement[input[i]].push(j)
    end
  end
end

letter_map.each do |k, v|
  alphabet_letter_frequency.each do |l, w|
    if w > v - margin_error and w < v + margin_error
      placement[k].each do |index|
        new_string[index] = "#{l}"
      end
      break
    end
  end
end

sum = 0
alphabet_letter_frequency.each do |k, v|
  sum += v / 100
end

puts sum / 26

puts new_string.join("")
