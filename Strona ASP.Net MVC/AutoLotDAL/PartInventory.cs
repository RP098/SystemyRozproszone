using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AutoLotDAL
{
    public partial class Inventory
    {
        public async Task<int> AddAsync(string Make, string Color, string CarNickName)
        {
            using (var context = new CarLot())
            {
                try
                {
                    return await Task.Run(() =>
                    {
                        var inventory = new Inventory() { Make = Make, Color = Color, CarNickName = CarNickName };
                        context.Inventory.Add(inventory);
                        context.SaveChanges();
                        return inventory.CarId;
                    });
                }
                catch (Exception ex)
                {
                    throw ex;
                }
            }
        }

    }
}
