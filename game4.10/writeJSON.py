# import json
#
# fileName = "my-data.json"
# jsonString = '{ "name":"dog", "ap":100, "hp":200, "dp":50, "ms":3, "as":5, "at":"single", "range":5, "knockback":3}'
# jsonString = json.loads(jsonString)
#
# file = open(fileName, "w")
# json.dump(jsonString, file)
# file.close()

import json
with open('test.json', 'w', encoding='utf-8') as f:
     json.dump([{ "name":"dog", "ap":100, "hp":200, "dp":50, "ms":3, "as":5, "at":"single", "range":5, "knockback":3}
                , { "name":"marshmellow", "ap":100, "hp":500, "dp":30, "ms":2, "as":5, "at":"single", "range":5, "knockback":3}]
                , f, indent=10, sort_keys=True, ensure_ascii=False)
