class Solution {
public:
	int compress(vector<char>& chars) {
		if (chars.size() == 1) return 1;
		char c = chars[0];
		int index = 1;
		int count = 1;
		int useful_length = 1;
		for (int i = 1; i < chars.size(); i++)
		{
			if (chars[i] == c) count++;
			else if (count != 1)
			{
				string val = to_string(count);
				int k = 0;
				while (k < val.size())
				{
					chars[index] = val[k];
					index++;
					k++;
					useful_length++;
				}
				c = chars[i];
				count = 1;
				chars[index] = c;
				index++;
				useful_length++;
			}
			else
			{
				c = chars[i];
				chars[index] = c;
				index++;
				count = 1;
				useful_length++;

			}
		}
		if (count != 1)
		{
			string val = to_string(count);
			int k = 0;
			while (k < val.size())
			{
				chars[index] = val[k];
				index++;
				k++;
				useful_length++;
			}
			count = 1;
		}

		return useful_length;


	}
};
