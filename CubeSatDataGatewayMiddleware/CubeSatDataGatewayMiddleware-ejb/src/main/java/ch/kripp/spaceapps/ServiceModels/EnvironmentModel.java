package ch.kripp.spaceapps.ServiceModels;

import ch.kripp.spaceapps.domain.entities.CfgEnvironmentDAO;

import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

/**
 * Created with IntelliJ IDEA.
 * User: frank
 * Date: 4/23/12
 * Time: 9:00 PM
 * To change this template use File | Settings | File Templates.
 */
@Stateless
public class EnvironmentModel {

    @PersistenceContext(unitName="CUBESAT")
    private EntityManager em;

    public CfgEnvironmentDAO querySingleCfgEnvironment()
    {
         CfgEnvironmentDAO res = em.find(CfgEnvironmentDAO.class, "DEV");
         return res;
    }

}
