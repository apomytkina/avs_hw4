Студент: Помыткина Анна Андреевна, БПИ194(1)

Вариант: 18

Описание задачи: Задача о наследстве. У старого дона Энрике было два сына, у каждого из сыновей – еще по два сына, каждый из которых имел еще по два сына. Умирая, дон Энрике завещал все свое богатство правнукам в разных долях. Адвокат дон Хосе выполнил задачу дележа наследства в меру своих способностей. Правнуки заподозрили адвоката в укрывательстве части наследства. Требуется создать многопоточное приложение, которое при известных сумме завещания дона Энрике и доле каждого наследника, проверяет честность адвоката. При решении использовать принцип дихотомии.

Используемая модель данных - цикл: Параллельно суммирумем доли всех сыновей, так как порядок проверки пропорций у сыновей не влияет на результат, оптимальнее проходиться по сыновьям обычным циклом, нежели использовать принцип дихотомии.

Источники по Open MP: 
https://www.youtube.com/watch?v=qLFB376KZPc
https://en.wikipedia.org/wiki/OpenMP
